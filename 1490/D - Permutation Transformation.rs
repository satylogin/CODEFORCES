use std::io::{self, Write};
use std::collections::HashMap;

fn populate_depth(
    d: usize, 
    arr: &Vec<usize>, 
    l: usize, 
    r: usize,
    depth_map: &mut HashMap<usize, usize>
) {
    let root: usize = *arr[l..=r].iter().max().unwrap();
    depth_map.insert(root, d);
    for i in l..=r {
        if arr[i] == root {
            if i != l {
                populate_depth(d + 1, arr, l, i - 1, depth_map);
            }
            if i != r {
                populate_depth(d + 1, arr, i + 1, r, depth_map);
            }
        }
    }
}

fn main() {
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let n: usize = sc.next();
        let arr: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let mut depth_map: HashMap<usize, usize> = HashMap::new();
        populate_depth(0, &arr, 0, n-1, &mut depth_map);
        (0..n).for_each(|i| write!(out, "{} ", depth_map[&arr[i]]).unwrap());
        writeln!(out).unwrap();
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
