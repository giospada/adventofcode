use crate::value::Value;

pub struct Pair {
    l: Value,
    r: Value,
}

impl Pair {
    pub fn from_pairs(l: Self, r: Self) -> Self {
        Self {
            l: Value::Pair(Box::new(l)),
            r: Value::Pair(Box::new(r)),
        }
    }

    pub fn from_str(string: &str) -> Result<(Self, usize), &str> {
        if !string.starts_with("[") {
            return Err("don't start with [");
        }

        let (l, middle) = Value::from_str(&string[1..])?;

        if !(&string[middle + 1..]).starts_with(",") {
            return Err("don't have ','");
        }

        let (r, mut end) = Value::from_str(&string[middle + 2..])?;

        end += middle + 2;

        if !string[..end + 1].ends_with("]") {
            return Err("don't end with ]");
        }

        Ok((Pair { l: l, r: r }, end + 1))
    }
    pub fn reduce(&mut self) {
        loop {
            if self.explode() {
                continue;
            }
            if self.split() {
                continue;
            }
            break;
        }
    }

    pub fn magnitude(&self) -> i64 {
        self.l.magnitude() * 3 + self.r.magnitude() * 2
    }

    fn search_who_explode(
        &self,
        depth: i32,
        counter_value: &mut i32,
        counter_pair: &mut i32,
    ) -> Option<(i32, i32)> {
        if depth >= 4 {
            if let Some(val) = self.get_both_numeric_value() {
                return Some(val);
            }
        }
        for t in [&self.l, &self.r] {
            match t {
                Value::Number(_) => {
                    *counter_value += 1;
                    *counter_pair += 1;
                }
                Value::Pair(pair) => {
                    *counter_pair += 1;
                    let res = pair.search_who_explode(depth + 1, counter_value, counter_pair);
                    if let Some(_) = res {
                        return res;
                    }
                }
            }
        }
        None
    }

    fn explode_searched(
        &mut self,
        counter_value: &mut i32,
        counter_pair: &mut i32,
        target: (i32, i32, i32),
        value: (i32, i32),
    ) {
        for current in [&mut self.l, &mut self.r] {
            match current {
                Value::Number(val) => {
                    *counter_value += 1;
                    *counter_pair += 1;
                    if *counter_value == target.1 {
                        *val += value.0;
                    }
                    if *counter_value == target.2 {
                        *val += value.1;
                    }
                }
                Value::Pair(pair) => {
                    *counter_pair += 1;
                    if counter_pair == &target.0 {
                        *current = Value::Number(0);
                    } else {
                        pair.explode_searched(counter_value, counter_pair, target, value);
                    }
                }
            }
        }
    }

    fn explode(&mut self) -> bool {
        let mut counter_value = 0;
        let mut counter_pair = 0;
        let number = self.search_who_explode(0, &mut counter_value, &mut counter_pair);
        if let Some(value) = number {
            let target = (counter_pair, counter_value, counter_value + 1);
            counter_pair = 0;
            counter_value = 0;
            self.explode_searched(&mut counter_value, &mut counter_pair, target, value);
            return true;
        }
        false
    }

    fn split(&mut self) -> bool {
        for t in [&mut self.l, &mut self.r] {
            match t {
                Value::Number(val) => {
                    if *val >= 10 {
                        *t = Value::Pair(Box::new(Pair {
                            l: Value::Number(*val / 2),
                            r: Value::Number(*val / 2 + *val % 2),
                        }));
                        return true;
                    }
                }
                Value::Pair(pair) => {
                    if pair.split() {
                        return true;
                    }
                }
            }
        }
        false
    }

    fn get_both_numeric_value(&self) -> Option<(i32, i32)> {
        match self.l {
            Value::Number(l) => match self.r {
                Value::Number(r) => {
                    return Some((l, r));
                }
                _ => {
                    return None;
                }
            },
            _ => {
                return None;
            }
        }
    }
}

impl Clone for Pair {
    fn clone(&self) -> Self {
        Self {
            l: self.l.clone(),
            r: self.r.clone(),
        }
    }

    fn clone_from(&mut self, source: &Self) {
        self.r = source.r.clone();
        self.l = source.l.clone();
    }
}
impl ToString for Pair {
    fn to_string(&self) -> String {
        format!("[{},{}]", self.l.to_string(), self.r.to_string())
    }
}
