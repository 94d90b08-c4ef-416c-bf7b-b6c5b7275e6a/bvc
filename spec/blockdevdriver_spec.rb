require 'blockdevdriver'

describe BlockDevDriver::LoopSparseFile do
  describe '#new' do
    context 'given a new file' do
      it 'creates it' do
        BlockDevDriver::LoopSparseFile.new 'test.bvc'
        expect(File.exist?('test.bvc')).to be true
      end
    end
    context 'given an existing correct file' do
      before do
        BlockDevDriver::LoopSparseFile.new 'test.bvc', 512*1024*1024
      end
      it 'accepts it' do
        BlockDevDriver::LoopSparseFile.new 'test.bvc'
        expect(File.exist?('test.bvc')).to be true
      end
      it 'has correct size' do
        expect(File.size?('test.bvc')).to eq(512*1024*1024)
      end
    end
    after do
      File.delete 'test.bvc'
    end
  end
  describe '.destroy' do
    context 'contructed with a file' do
      before do
        @lsf = BlockDevDriver::LoopSparseFile.new 'test.bvc'
      end
      it 'removes this file on destroy' do
        expect(File.exist?('test.bvc')).to be true
        @lsf.destroy
        expect(File.exist?('test.bvc')).to be false
      end
      after do
        File.delete 'test.bvc'
      rescue Errno::ENOENT
      end
    end
  end
  describe '.enable' do
    context 'ready to be used' do
      before do
        @lsf = BlockDevDriver::LoopSparseFile.new 'test.bvc'
      end
      it 'provide and block device' do
        @lsf.enable do |f|
          expect(File.blockdev?(f)).to be true
        end
      end
      after do
        @lsf.destroy
      end
    end
  end
end
