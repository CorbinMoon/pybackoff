from setuptools import setup, find_packages

setup(
    name='pybackoff',
    version='0.0.10',
    url='https://github.com/CorbinMoon/pybackoff',
    author='Corbin Moon',
    author_email='clangmoon@gmail.com',
    license='MIT',
    classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8'
    ],
    project_urls={
        'Source': 'https://github.com/CorbinMoon/pybackoff'
    },
    packages=find_packages(),
    python_requires='>=3.6',
    package_data={
        'pybackoff': ['libpybackoff.so']
    }
)