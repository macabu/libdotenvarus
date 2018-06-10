project('libdotenvarus', 'c',
	version : '1.0.0',
	default_options : ['c_std=c11'])

libdotenvarus_sources = ['dotenvarus.c']
libdotenvarus_test_sources = ['test/test.c']

libdotenvarus_a = static_library('dotenvarus', libdotenvarus_sources, install: false)
libdotenvarus_so = shared_library('dotenvarus', libdotenvarus_sources, install: false)

lib_test = executable('dotenvarus_test', libdotenvarus_test_sources, link_with : libdotenvarus_a, install : false)
