mod ds {
    use std::cmp::{min, max};

    #[derive(Clone, Debug)]
    pub struct Node {
        pub l: i32,
        pub r: i32,
        pub v: i32,
    }

    #[derive(Debug)]
    pub struct SegTree {
        tree: Vec<Node>,
        arr: Vec<char>,
        n: usize
    }

    #[inline]
    pub fn intersect(x: Node, y: Node) -> Node {
        Node {
            l: min(x.l, y.l + x.v),
            r: max(x.r, y.r + x.v),
            v: x.v + y.v,
        }
    }

    impl SegTree {
        pub fn new(n: usize, arr: Vec<char>) -> SegTree {
            let mut tree = SegTree {
                tree: vec![Node{l: 0, r: 0, v: 0}; n * 4],
                arr,
                n
            };
            tree.create(1, 1, n);
            tree
        }

        fn create(&mut self, n: usize, start: usize, end: usize) {
            if start == end {
                self.tree[n] = if self.arr[start -1] == '+' {
                    Node{l: 0, r: 1, v: 1}
                } else {
                    Node{l: -1, r: 0, v: -1}
                };
            } else if start < end {
                let mid = (start + end) >> 1;
                self.create(n<<1, start, mid);
                self.create(n<<1|1, mid+1, end);
                self.tree[n] = intersect(self.tree[n<<1].clone(), self.tree[n<<1|1].clone());
            }
        }

        pub fn query(&self, n: usize, start: usize, end: usize, l: usize, r: usize) -> Node {
            let ans: Node = if start > r || end < l || start > end || l > r {
                Node { l: 0, r: 0, v: 0 }
            } else if start >= l && end <= r {
                self.tree[n].clone()
            } else {
                let mid = (start + end) >> 1;
                intersect(
                    self.query(n<<1, start, mid, l, r),
                    self.query(n<<1|1, mid+1, end, l, r)
                )
            };
            ans
        }
    }
}

fn main() {
    use std::io::{self, Write};
 
    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let tc: usize = sc.next();
    for _ in 0..tc {
        let (n, q): (usize, usize) = (sc.next(), sc.next());
        let op: Vec<char> = sc.next::<String>().chars().collect();
        let tree: ds::SegTree = ds::SegTree::new(n, op);
        for _ in 0..q {
            let (l, r): (usize, usize) = (sc.next(), sc.next());
            let l = tree.query(1, 1, n, 1, l - 1);
            let r = tree.query(1, 1, n, r + 1, n);
            let x = ds::intersect(l, r);
            writeln!(out, "{}", x.r - x.l + 1).unwrap();
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
