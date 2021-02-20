use std::collections::{BTreeMap, BTreeSet};

fn main() {
    use std::io::{self, Write};

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, m): (usize, usize) = (sc.next(), sc.next());
        let a: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let b: Vec<usize> = (0..n).map(|_| sc.next()).collect();
        let c: Vec<usize> = (0..m).map(|_| sc.next()).collect();
        let mut ans: Vec<usize> = vec![usize::MAX; m];
        let mut defects: BTreeMap<usize, Vec<usize>> = BTreeMap::new();
        let mut colors: BTreeMap<usize, BTreeSet<usize>> = BTreeMap::new();
        let mut def_count = 0;
        for i in 0..n {
            if a[i] != b[i] {
                defects.entry(b[i]).or_insert(vec![]).push(i);
                def_count += 1;
            }
            colors.entry(a[i]).or_insert(BTreeSet::new()).insert(i);
        }
        for i in 0..m {
            if defects.contains_key(&c[i]) && defects.get(&c[i]).unwrap().len() > 0 {
                let j = defects.get_mut(&c[i]).unwrap().pop().unwrap();
                ans[i] = j;
                def_count -= 1;
                colors.get_mut(&a[j]).unwrap().remove(&j);
                colors.entry(b[j]).or_insert(BTreeSet::new()).insert(j);
            } else if colors.contains_key(&c[i]) && colors.get(&c[i]).unwrap().len() > 0 {
                let &j = colors.get_mut(&c[i]).unwrap().iter().clone().next().unwrap();
                ans[i] = j;
            }
        }
        if ans[m-1] == usize::MAX || def_count != 0 {
            writeln!(out, "NO").unwrap();
            continue;
        }
        for i in 0..m {
            if ans[i] == usize::MAX {
                ans[i] = ans[m-1];
            }
        }
        writeln!(out, "YES").unwrap();
        (0..m).for_each(|i| write!(out, "{} ", ans[i] + 1).unwrap());
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
