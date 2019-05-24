# hypeRscan

Rcpp package to create [hyperscan](https://www.google.com) string functions

![Benchmark](https://raw.githubusercontent.com/gmcrosh/hypeRscan/master/benchmark/benchmark.png)

Benchmark on [All's well that ends well](http://shakespeare.mit.edu/allswell/full.html) using the regular expression `[L|l]ord`. Hypyerscan typically performs much faster on larger task, charcter vectors with over 100 values.

## Install

You must have hyperscan installed by either [building it](https://intel.github.io/hyperscan/dev-reference/getting_started.html#very-quick-start) or installing from a [package](https://packages.ubuntu.com/bionic/libhyperscan-dev)

```
# apt-get install libhyperscan-dev
install_github("gcrot/hypeRscan")
```

It is unclear if the precompiled packages are a [fat-runtime](https://intel.github.io/hyperscan/dev-reference/getting_started.html#fat-runtime), so for best performance it is recommended that you build hyperscan from source. 
