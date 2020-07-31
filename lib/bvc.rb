# frozen_string_literal: true

require_relative 'devdriver'

class BVCRepo
  # Binary Version control repoistory objects

  def initialize(file, size = 512)
    @block_dev = BlockDevDriver::LoopSparseFile.new file, size
    @pv_name = @block_dev.file_name
    @lv_name = 'root'
    @device_path = File.join '/', 'dev', @pv_name, 'root'
    @mount_path = File.join '/', 'tmp', "bvc.#{@pv_name}"
  end

  def enable
    @block_dev.enable { |block_dev_file_name|
      puts 'Make PV on it'
      `sudo pvcreate #{block_dev_file_name}`
      puts 'Make Volume group on the top of it'
      `sudo vgcreate #{@pv_name} #{block_dev_file_name}`
      puts 'Create thin pool volume'
      `sudo lvcreate --type thin-pool -L #{@block_dev.requested_size * 0.8} #{@pv_name}/pool`
      puts 'Create root LV'
      `sudo lvcreate --type thin -V #{@block_dev.requested_size * 0.8} --thinpool #{@pv_name}/pool --thin --name #{@lv_name}`
      puts 'Make FS on root LV'
      `sudo mkfs.ext3 #{@device_path}`
      puts 'Mount root LV'
      Dir.mkdir File.join('/', 'tmp', "bvc.#{@pv_name}"), 0700
      `sudo mount #{@device_path} #{@mount_path}`
    }
  end

  # def commit
  #   `sudo umount #{@device_path}`
  #   `sudo lvcreate --type thin --snapshot #{@pv_name}/#{@lv_name}`
  #   `sudo mount #{@device_path} #{@mount_path}`
  # end

  def info
    puts `sudo pvs`
    puts `sudo vgs`
    puts `sudo lvs`
  end

  def destroy
    @block_dev.destroy
    # `sudo pvremove #{@pv_name}`
  end
end
