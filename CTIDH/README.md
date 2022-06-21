Prerequisites: Intel or AMD CPU with `adcx`/`adox`: i.e., Broadwell,
Skylake, or newer. Linux with standard development tools plus `clang`
plus `valgrind`.

To download and unpack the latest version:

        wget -m https://ctidh.isogeny.org/high-ctidh-latest-version.txt
        version=$(cat ctidh.isogeny.org/high-ctidh-latest-version.txt)
        wget -m https://ctidh.isogeny.org/high-ctidh-$version.tar.gz
        tar -xzf ctidh.isogeny.org/high-ctidh-$version.tar.gz
        cd high-ctidh-$version

To compile, test for functionality, tune for multiplications, and tune
for cycles, for all selected sizes (511, 512, 1024):

        make

This takes a while, more than half an hour on a 3GHz Skylake core,
because of all the testing and tuning. Any test failure will stop the
build process. (You can run `make 512` to focus on size 512.)

The functionality testing included in `make` does not include a
constant-time test. To run a constant-time test:

        make timecop

For benchmarks regarding, e.g., size-511 code tuned for multiplications:

        ./bench511mults 16383 > bench511mults.out.16383

This runs a million experiments: more precisely, 16383 experiments for
each of 65 keys. This takes hours, and generates hundreds of megabytes
of data. Each measurement includes, for validation and separately for
the action, a "`mulsq`" count that includes both multiplications and
squarings, a "`sq`" count that includes only squarings, an "`addsub`"
count that includes additions and subtractions, and a cycle count (which
for multiplication-tuned code isn't far behind cycle-tuned code). The
action also shows "`stattried`" counts showing the number of times each
batch occurred publicly in an atomic block.

To analyze average costs and standard deviations:

        ./analyze-costs < bench511mults.out.16383 \
        > bench511mults.out.16383.analyze-costs

Statistics are printed for each of the 65 keys separately, and
("`total`") for the all of the experiments together.

To analyze whether the `stattried` counts are as expected:

        ./analyze-pr < bench511mults.out.16383 \
        > bench511mults.out.16383.analyze-pr

This prints, for each batch, 1-1/p times the number of times the batch
was tried divided by the batch bound, where p is the smallest prime in
the batch.

For various size-511 microbenchmarks:

        ./umults511
        ./ubench511

To select other CSIDH sizes and other CTIDH parameters (subject to
various undocumented restrictions), edit the table at the top of
`autogen` and run `./autogen; make`.
