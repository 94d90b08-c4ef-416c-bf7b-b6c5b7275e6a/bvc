# frozen_string_literal: true

require 'json'
# require 'losetup'

module BlockDevDriver
  class LoopSparseFile
    # Underlying block device represented by a file mounted as a loop device
    attr_reader :requested_size
    attr_reader :file_name

    def initialize file, size=512*1024*1024
      current_size = File.size? file
      @requested_size = size
      @file_name = file
      if current_size.nil?
        File.open(@file_name, 'w') do |f|
          f.truncate(@requested_size)
        end
      elsif current_size < @requested_size
        raise NotEnoughFileSize
      elsif current_size > @requested_size
        p "File #{@file_name} is bigger than expected, ignoring"
      end
    end

    def enable!
#      ld = Losetup::LoopDevice.new
#      ld.create @file_name
      `sudo losetup -f #{@file_name}`
      lo_dev_info = JSON.parse `sudo losetup -JO NAME -j #{@file_name}`
      lo_dev_name = lo_dev_info['loopdevices'].first['name']
      yield lo_dev_name if block_given?
      `sudo losetup --detach #{lo_dev_name}`
    end

    def destroy!
      File.delete @file_name
    end

  end

  class NotEnoughFileSize < RuntimeError
  end

end
