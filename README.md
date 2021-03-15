# pasgen
CLI Password Generator written in C++

[![license](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/OsoianMarcel/promise-all-always/blob/master/LICENSE)

## Build
Run `make` then check the output folder

## How to use
Help section:
```
        [CLI Password Generator]
-l      Password length (default: 32)
-c      Caracter set (n: number, l: lowercase, u: uppercase, s: symbols) (default: nul)
-n      Number of passwords to generate (default: 1)
-h      Help
```
Example: 
```
# ./output/pasgen -l 16 -c nuls -n 3
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

[issue tracker]: https://github.com/OsoianMarcel/promise-all-always/issues
[Git repository]: https://github.com/OsoianMarcel/promise-all-always
[MIT license]: LICENSE