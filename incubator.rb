#!ruby

$LOAD_PATH << File.dirname(__FILE__)

require 'confmaker'
require 'lib/bvc'

# ConfMaker.define_desc 'Binary Version Control'

# config = ConfMaker.define_options [
#   ConfOptions::String.new(
#     :name => :action,
#     :alias => :s,
#     :desc => "What to do with repository?",
#     :value => 'help',
#     :check_regexp => /(help|commit|init|mount)/
#   ),
#   ConfOptions::String.new(
#     name: :repository,
#     alias: :r,
#     desc: 'Repository loop file name',
#     check_regexp: /[a-zA-Z0-9\-]*\.bvc/
#   )
# ]

# config.merge! ConfSources::CommandLine.new
# config.validate!

# p config

repo = BVCRepo.new 'test.bvc'
repo.enable

#repo.info

#repo.deinit