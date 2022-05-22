# ccal

By Nikolaus J. Reichert <nikolaus@njreichert.ca>

ccal is a CLI-based Reverse Polish notation calculator.

## Building

1. Create a `build` folder and call `cmake` and `make`.
2. Install with `sudo make install`.

```
mkdir build && cd build
cmake ..
make
sudo make install
```

## Usage

`ccal [options] [statement]`

If no option is given, and an RPN statement (with each token delimited by spaces)
is passed to the program, that statement will be evaluated directly by the program.
For example,

```
$ ccal 1 2 +
3
```

### Options
`-h` `--help` - Print a help statement.
`-v` `--version` - Print the program's version.

## Available Operators

$ + - \times \div $ `+ - * /`

$\sqrt{x}$ `sqrt`

$e^x$ `exp`

$sin(x)$ `sin`

$cos(x)$ `cos`

$tan(x)$ `tan`

$Sin^{-1}(x)$ `arcsin`

$Cos^{-1}(x)$ `arccos`

$Tan^{-1}(x)$ `arctan`

$log\_{10}(x)$ `log`

$ln(x)$ `ln`

$log\_{2}(x)$ `log2`

$|x|$ `abs`

$\frac{1}{x}$ `inv`

$y^x$ `^` or `pow`

$\sqrt[x]{y}$ `nroot`

$x!$ `!`

## Available Commands

Clear stack `clear`

Sum stack `sum`

## Available Constants

$\pi$ `pi`

$e$ `e`

