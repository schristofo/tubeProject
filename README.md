# The Five Formula Project

Five Formula is a command line project parsing a sequence of characters in order to generate a number. The model built from this sequence is consisted of four mathematical calculations (addition, multiplication, power, division) of thee number 5.

## Examples

```bash
-+-/-^-
```
is translated into 5 plus 5 divided by 5 to the power of 5 which is 32. Notice that every calculation is separated with dashes from the next and previous one, as well as, the whole model starts with a dash and ends with a dash

## Compile

Use the gcc compiler to compile the project. Type the following to compile:

```bash
make
```

## Usage

```bash
./bin/skata <input-file-path>
```
or
```bash
cd bin
./skata <input-file-path>
```

to execute.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://choosealicense.com/licenses/mit/)
