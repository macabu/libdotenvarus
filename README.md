# Dotenvarus
:bookmark_tabs: A simple to use library to fetch local .env variables.

---

## Building
In order to build `dotenvarus`, you are going to need the following dependencies:
* `gcc`
* `meson`
* `ninja`

And then you should remove any leftover `build` folders, at the root path of the project.  
> `rm -rf build`  

Create the folder again:  

> `mkdir buid`

Go into it:

> `cd build`

Prepare the build with `meson`:

> `meson ..`

Run `ninja`!

> `ninja`

Then, if everything went as expected, you should see three files inside the `build` folder. Namely:

* `dotenvarus_test` - The test executable
* `libdotenvarus.a` - Static library
* `libdotenvarus.so` - Dynamic library

In order to link a project with the static library for example, you should copy `dotenvarus.h` and `libdotenvarus.a` to your project folder.  
With the `examples` folder, we can copy these files and then simply run `gcc example.c libdotenvarus.a` and the output `a.out` should be linked with the library.

---

## Usage

You can change the name of the `env` file by changing the value of `ENV_FILE` preprocessor.

There are basically three methods that can be called:
* `set_env_path` - set a path to `ENV_FILE`
* `get_env_path` - returns the path that will be appended when looking for `ENV_FILE`
* `get_var` - retrieves a value from the specified environment variable inside `ENV_FILE`