use std::cmp::max;

fn divisors() -> Vec<Vec<usize>> {
    let lim: usize = 2e5 as usize;
    let mut div: Vec<Vec<usize>> = vec![vec![]; lim + 1];
    for i in 1..=lim {
        for j in (2 * i..=lim).step_by(i) {
            div[j].push(i);
        }
    }
    div
}

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let div = divisors();
    let mut ans: Vec<usize> = vec![0; 200001];
    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let mut array: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        array.sort();
        let mut max_len: usize = 0;
        for &x in array.iter() {
            for &d in div[x].iter() {
                ans[x] = max(ans[x], ans[d]);
            }
            ans[x] += 1;
            max_len = max(max_len, ans[x]);
        }
        for &x in array.iter() {
            ans[x] = 0;
        }
        writeln!(out, "{}", n - max_len).unwrap();
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
