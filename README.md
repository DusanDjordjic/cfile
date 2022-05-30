# Create file - cfile
Program for creating default files

## Instalation
1. Clone the repo `git clone https://github.com/DusanDjordjic/cfile.git`
2. `cd cfile`
3. Copy `.cfile.conf` to your home directory
4. Edit main.cpp and change `config_file_name` so it points to the your `.cfile.conf`
5. Build it. I use g++ but you can use whatever you want `g++ main.cpp filetype.cpp -o cfile`
6. Copy `cfile` to `/usr/bin/` -> `sudo cp cfile /usr/bin/cfile`.
> **_NOTE:_** Feel free to rename it to whetever you like e.g. `sudo cp cfile /usr/bin/genfile` and then run `genfile cpp main`.

## Usage
1. run `cfile (filetype) (filename) (destination (default ./))`.
> **_NOTE:_** It automatically adds extension. `cfile cpp main` will create main.cpp in current working directory.

## Supported file types
cpp, c, node

### Customization
To make `cfile` work you need to edit `main.cpp` as said in the Installation step, but feel free to change the name of the `.cfile.conf` to whatever you want.

Also, change the path to whatever you want. In the main.cpp you will find two strings `start_key` and `end_key` these define blocks of text that will be written to a 'default' file.

It works like this `start_key filetype extension_that_will_be_added (text_that_will_be_copied) end_key`. You can make your default configurations and feel free to submit them to this repo :D.
