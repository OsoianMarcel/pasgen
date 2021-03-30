# pasgen
CLI Password Generator written in C++

[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/OsoianMarcel/promise-all-always/blob/master/LICENSE)

## Building
Run `make` then check the output folder

## How to use
Help section:
```
$ ./output/pasgen -h
        [CLI Password Generator]
-l      Password length (default: 32)
-c      Caracter set (n: number, l: lowercase, u: uppercase, s: symbols) (default: nul)
-n      Number of passwords to generate (default: 1)
-us     Generate and use additionally user seed
-h      Help
```

Example #1: Generate a password with 32 characters (no symbols)
```
$ ./output/pasgen 
XUr9MG308gSnXstz4x1Q1118P3WHOTil
```

Example #2: Generate [-n 3] passwords, with [-l 16] characters, with following character sets: [-c] [n]umeric, [u]ppercase, [l]owercase and [s]ymbol characters
```
$ ./output/pasgen -n 3 -l 16 -c nuls
D8S"n1}18Ajr`sP2
F*_}w!lC9<Fh~[+5
8#D2rW"4'h0=Jz36
```

## Contribute

Contributions to the package are always welcome!

* Report any bugs or issues you find on the [issue tracker].
* You can grab the source code at the package's [Git repository].

## License

All contents of this package are licensed under the [MIT license].

[issue tracker]: https://github.com/OsoianMarcel/pasgen/issues
[Git repository]: https://github.com/OsoianMarcel/pasgen
[MIT license]: LICENSE