from distutils.core import setup, Extension

module1 = Extension(
	'complexNumbers',
	 sources = ['complexNumbers.c']
)

setup(
	name = 'complexNumbers',
	version = '1.1.1',
	description = 'Simple module', 
	ext_modules = [module1]
)