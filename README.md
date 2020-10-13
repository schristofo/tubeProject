# The Five Formula Project

Five Formula is a command line project parsing a sequence of characters in order to generate a number. The model built from this sequence is consisted of four mathematical calculations (addition, multiplication, power, division) of the number 5.

## Format

The acceptable format of the formulas/models is:
  `- <function> - <function> - ... - <function> -`
 where <function> can be substituted with one of the following values: `+`, `*`, `^`, `/`.

## Examples

- `model: -*-` is translated into `5*5=25`.
- `model: -+-/-^-` is translated into `((5+5)/5)^5=32`. 
- `model: -+-+-/-+` is translated into `(((5+5)+5)/5)+5=8`.
- `model: -+-/+` will generate the error `Error: Final dash (-) expected`.

Notice that every calculation is separated with dashes from the next and previous one, as well as, the whole model starts with a dash and ends with a dash

## Compile

Use the gcc compiler to compile the project. Type the following to compile:

```bash
make
```

## Usage

```bash
./bin/5f <input-file-path>
```
or
```bash
cd bin
./5f <input-file-path>
```

to execute.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
