use std::cmp::Ordering;
use std::collections::btree_set::BTreeSet;
use std::collections::VecDeque;
use std::io;
use std::io::Write;

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut scan = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let t: usize = scan.next();
    for _ in 0..t {
        let n: usize = scan.next();
        let m: usize = scan.next();
        let mut array: Vec<u64> = (0..n).map(|_| scan.next()).collect();
        array.sort();
        let mut pref_sum: Vec<u64> = vec![0; n];
        pref_sum[0] = array[0];
        for i in 1..n {
            pref_sum[i] = pref_sum[i - 1] + array[i];
        }
        let mut valid_sum: BTreeSet<u64> = BTreeSet::new();
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();
        q.push_back((0, n - 1));

        while !q.is_empty() {
            let (l, r) = q.pop_front().unwrap();
            let sum: u64 = pref_sum[r] - (if l == 0 { 0 } else { pref_sum[l - 1] });
            valid_sum.insert(sum);
            if array[l] == array[r] {
                continue;
            }
            let mid: u64 = (array[l] + array[r]) >> 1;
            let partition_idx = array.binary_search_by(
                |x| if *x <= mid {Ordering::Less} else {Ordering::Greater}
            ).unwrap_err();
            q.push_back((l, partition_idx - 1));
            q.push_back((partition_idx, r));
        }

        for _ in 0..m {
            let x: u64 = scan.next();
            writeln!(out, "{}", if valid_sum.contains(&x) { "Yes" } else { "No" }).unwrap();
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
