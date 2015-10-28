APPNAME = 'frame_number'
VERSION = '1.0.0'

top = '.'
out = 'build'

def options(opt):
	opt.load('compiler_cxx')

def configure(conf):
	conf.load('compiler_cxx')
	conf.check_cfg(package = 'opencv', args = '--cflags --libs')
	conf.env.store('conf.log')


def build(bld):
	bld.recurse('src')
	bld(
		features = 'cxx cxxprogram',
		target = 'frame_number',
		use = 'myobjects',
    )