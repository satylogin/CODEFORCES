use std::collections::BTreeMap;
use std::cmp::max;

mod sieve {
    static N: usize = 1e6 as usize;

    pub struct Prime {
        lp: Vec<usize>
    }

    impl Prime {
        fn sieve() -> Vec<usize> {
            let mut p: Vec<usize> = vec![0; N + 5];
            for i in 2..=N {
                for j in (i..=N).step_by(i) {
                    if p[j] == 0 {
                        p[j] = i;
                    }
                }
            }
            p
        }

        pub fn new() -> Prime {
            Prime {
                lp: self::Prime::sieve()
            }
        }

        pub fn reduce(&self, mut x: usize) -> usize {
            let mut ans: usize = 1;
            while x > 1 {
                let y = self.lp[x];
                let mut cnt: usize = 0;
                while x % y == 0 {
                    x /= y;
                    cnt += 1;
                }
                if cnt & 1 == 1 {
                    ans *= y;
                }
            }
            ans
        }
    }
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let prime = sieve::Prime::new();

    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let arr: Vec<usize> = (0..n).map(|_| prime.reduce(sc.next())).collect();
        let mut freq: BTreeMap<usize, usize> = BTreeMap::new();
        for x in arr {
            *freq.entry(x).or_insert(0) += 1;
        }
        let mut ans0: usize = 0;
        let mut ans1: usize = 0;
        for (_, &y) in freq.iter() {
            ans0 = max(ans0, y);
            if y & 1 == 0 {
                ans1 += y;
            }
        }
        if let Some(&x) = freq.get(&1) {
            ans1 += if x & 1 == 0 {0} else {x};
        }
        ans1 = max(ans1, ans0);
        let q: usize = sc.next();
        for _ in 0..q {
            let w: i64 = sc.next();
            writeln!(out, "{}", if w == 0 {ans0} else {ans1}).unwrap();
        }
    }
}

#[allow(dead_code)]
mod cf_scanner {
    use std::io;
    use std::str::{FromStr, SplitAsciiWhitespace};

    pub struct Scanner<R> {
        reader: R,
        buf_str: Vec<u8>,
        buf_iter: SplitAsciiWhitespace<'static>,
    }

    impl<R: io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Scanner<R> {
            Scanner {
                reader,
                buf_str: Vec::new(),
                buf_iter: "".split_ascii_whitespace(),
            }
        }

        pub fn next<T: FromStr>(&mut self) -> T {
            loop {
                if let Some(token) = self.buf_iter.next() {
                    return token.parse().ok().expect("Failed parse");
                }
                self.buf_str.clear();
                self.reader
                    .read_until(b'\n', &mut self.buf_str)
                    .expect("Failed read");
                self.buf_iter = unsafe {
                    let slice = std::str::from_utf8_unchecked(&self.buf_str);
                    std::mem::transmute(slice.split_ascii_whitespace())
                }
            }
        }
    }
}
