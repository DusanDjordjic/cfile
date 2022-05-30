# Create file - cfile
Program for creating default files

## Instalation
1. Clone the repo `git clone https://github.com/DusanDjordjic/cfile.git`
2. `cd cfile`
3. Build it. I use g++ but you can use whatever you want `g++ main.cpp filetype.cpp -o cfile`
4. Copy `cfile` to `/usr/bin/` -> `sudo cp cfile /usr/bin/cfile`.
> **_NOTE:_** Feel free to rename it to whetever you like e.g. `sudo cp cfile /usr/bin/genfile` and then run `genfile cpp main`.

## Usage
1. run `cfile (filetype) (filename) (destination (default ./))`.
> **_NOTE:_** It automatically adds extension. `cfile cpp main` will create main.cpp in current working directory.

## Supported file types
cpp, c, node

### Features to add
1. Configuration so the user can override default file contents and make his own.
2. Make it so that in configuration user can define his type, an extension that will be appended, and file contents that will be included in the generated file.
