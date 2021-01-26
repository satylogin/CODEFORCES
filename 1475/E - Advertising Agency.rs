use std::cmp::{min, max};

static MOD: i64 = 1e9 as i64 + 7;

fn inv(mut a: i64) -> i64 {
    let mut ans: i64 = 1;
    let mut b: i64 = MOD - 2;
    while b > 0 {
        if b & 1 == 1 {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    ans
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let mut fact: Vec<i64> = vec![0; 10000];
    fact[0] = 1;
    for i in 1..10000 {
        fact[i] = (i as i64 * fact[i-1]) % MOD;
    }

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, k): (usize, usize) = (sc.next(), sc.next());
        let mut array: Vec<i32> = (0..n).map(|_| sc.next()).collect();
        array.sort();
        array.reverse();
        let x = array[k-1];
        let (mut l, mut r): (usize, usize) = (k-1, k-1);
        for i in 0..n {
            if array[i] == x {
                l = min(l, i);
                r = max(r, i);
            }
        }
        let ans = (fact[r - l + 1] * (inv(fact[k - l]) * inv(fact[r + 1 - k]) % MOD)) % MOD;
        writeln!(out, "{}", ans).unwrap();
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

#[allow(dead_code)]
mod cds {
    use std::collections::BTreeMap;
    use std::fmt::Debug;

    #[derive(Debug, Clone)]
    pub struct Multiset<K: Ord> {
        pub freq: BTreeMap<K, usize>
    }

    impl<K: Ord> Multiset<K> {
        pub fn new() -> Multiset<K> {
            Multiset {
                freq: BTreeMap::new()
            }
        }

        pub fn insert(&mut self, val: K) {
            *self.freq.entry(val).or_insert(0) += 1;
        }

        pub fn erase(&mut self, val: K) -> bool {
            let mut state: usize = 0;
            if let Some(x) = self.freq.get_mut(&val) {
                *x -= 1;
                state = if *x == 0 {2} else {1};
            }
            if state == 2 {
                self.freq.remove(&val);
            }
            state > 0
        }

        pub fn begin(&self) -> Option<&K> {
            self.freq.keys().next()
        }

        pub fn rbegin(&self) -> Option<&K> {
            self.freq.keys().next_back()
        }

        pub fn is_empty(&self) -> bool {
            self.freq.is_empty()
        }
    }
}
