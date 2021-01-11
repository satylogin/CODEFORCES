use std::collections::BTreeSet;

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let mut poem: Vec<char> = sc.next::<String>().chars().collect();
        let mut changes: i32 = 0;
        for i in 0..poem.len() {
            let mut dist: bool = true;
            if (i > 0 && poem[i] == poem[i - 1]) || (i > 1 && poem[i] == poem[i-2]) {
                dist = false;
            }
            if dist {
                continue;
            }
            changes += 1;
            let mut dist: BTreeSet<char> = BTreeSet::new();
            for j in (i as isize - 2)..=(i as isize + 2) {
                if j >= 0 && j < poem.len() as isize {
                    dist.insert(poem[j as usize]);
                }
            }
            for c in vec!['a', 'b', 'c', 'd', 'e', 'f'] {
                if !dist.contains(&c) {
                    poem[i] = c;
                }
            }
        }
        writeln!(out, "{}", changes).unwrap();
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
