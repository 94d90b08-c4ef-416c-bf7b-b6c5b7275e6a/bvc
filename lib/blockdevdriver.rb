# frozen_string_literal: true

require 'json'

module BlockDevDriver

  class LoopSparseFile

    attr_reader :requested_size
    attr_reader :file_name

    @requested_size = 512 * 1024 * 1024
    @file_name = nil

    def initialize file, size=nil
      current_size = File.size? file
      if current_size
        raise NotEnoughFileSize if current_size < size
      else
        # Create a file
        `sudo truncate -s #{size} #{file}`
      end
      @file_name = file
      @requested_size = size if size
    end

    def enable
      `sudo losetup -f #{@file_name}`
      lo_dev_info = JSON.parse `sudo losetup -JO NAME -j #{@file_name}`
      lo_dev_name = lo_dev_info['loopdevices'].first['name']
      yield lo_dev_name if block_given?
      `sudo losetup --detach #{lo_dev_name}`
    end

    def destroy
      File.delete @file_name
    end

  end

  class NotEnoughFileSize < RuntimeError
  end

end
