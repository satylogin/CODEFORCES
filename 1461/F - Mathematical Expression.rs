use std::cmp::min;

fn joiner(array: Vec<char>, pattern: &char) -> String {
    let mut ans: String = String::new();
    ans.push(array[0]);
    for i in 1..array.len() {
        ans.push(*pattern);
        ans.push(array[i]);
    }
    ans
}

fn get_boundary(array: &[char]) -> (usize, usize) {
    let (mut l, mut r) = (0, 0);
    for (i, c) in array.iter().enumerate() {
        if *c != '1' {
            l = i;
            break;
        }
    }
    for (i, c) in array.iter().enumerate().rev() {
        if *c != '1' {
            r = i;
            break;
        }
    }
    (l, r)
}

fn solve(array: &[char]) -> String {
    let mut ans: String = String::new();
    let mut pref_prod: Vec<u32> = vec![1; array.len()+1];
    for (i, c) in array.iter().enumerate() {
        pref_prod[i+1] = min(pref_prod[i] * (*c as u8 - b'0') as u32, 1e8 as u32);
    }
    if pref_prod[array.len()] >= 1e8 as u32 {
        let (l, r) = get_boundary(array);
        for (i, &c) in array.iter().enumerate() {
            if i != 0 {
                ans.push(if i <= l || i > r {'+'} else {'*'});
            }
            ans.push(c);
        }
    } else {
        let mut dp: Vec<u32> = vec![0; array.len() + 1];
        let mut parent: Vec<usize> = vec![0; array.len() + 1];
        let mut non_ones: Vec<usize> = vec![];
        for (i, &c) in array.iter().enumerate() {
            let d: u32 = (c as u8 - b'0') as u32;
            dp[i + 1] = dp[i] + d;
            parent[i + 1] = i + 1;
            if d != 1 {
                for &idx in non_ones.iter() {
                    if pref_prod[i + 1] / pref_prod[idx] + dp[idx] > dp[i + 1] {
                        dp[i + 1] = pref_prod[i + 1] / pref_prod[idx] + dp[idx];
                        parent[i + 1] = idx + 1;
                    }
                }
                non_ones.push(i);
            }
        }
        let mut idx: usize = array.len();
        while idx > 0 {
            let p = parent[idx];
            for i in (p..idx+1).rev() {
                ans.push(array[i-1]);
                ans.push('*');
            }
            ans.pop();
            ans.push('+');
            idx = p - 1;
        }
        if ans.ends_with('+') {
            ans.pop();
        }
        ans = ans.chars().rev().collect::<String>();
    }


    ans
}

fn main() {
    use std::io;
    use std::io::Write;

    let (stdin, stdout) = (io::stdin(), io::stdout());
    let mut sc = cf_scanner::Scanner::new(stdin.lock());
    let mut out = io::BufWriter::new(stdout.lock());

    let n: usize = sc.next();
    let array: Vec<char> = (0..n).map(|_| sc.next()).collect();
    let ops: String = sc.next();

    let mut ans: String = String::new();
    if ops.len() == 1 {
        ans = joiner(array, &ops.chars().next().unwrap());
    } else if ops == "-+" || ops == "+-" {
        ans = joiner(array, &'+');
    } else if ops.contains('*') && ops.contains('+') {
        let mut l: usize = 0;
        let mut range: bool = false;
        for i in 0..n {
            if array[i] == '0' {
                if range {
                    ans.push('+');
                    ans.push_str(solve(&array[l..i]).as_str());
                    range = false;
                }
                ans += "+0";
            } else {
                if !range {
                    range = true;
                    l = i;
                }
            }
        }
        if range {
            ans.push('+');
            ans.push_str(solve(&array[l..n]).as_str());
        }
        if ans.starts_with('+') {
            ans = String::from(&ans[1..]);
        }
    } else if ops.contains('*') && ops.contains('-') {
        ans.push(array[0]);
        for i in 1..n {
            ans.push(if array[i] == '0' {'-'} else {'*'});
            ans.push(array[i]);
        }
    }
    writeln!(out, "{}", ans).unwrap();
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
