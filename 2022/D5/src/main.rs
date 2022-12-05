use regex::Regex;
use std::cell::RefCell;
use std::collections::VecDeque;
use std::fs;
use std::rc::Rc;

const FILE_INPUT: &str = "input.txt";

//type Input = Vec<&str>;
type Output = String;

#[derive(Clone)]
struct Input {
    state: Vec<VecDeque<char>>,
    moves: Vec<(i32, i32, i32)>,
}

impl Input {
    fn new() -> Self {
        Self {
            state: vec![],
            moves: vec![],
        }
    }

    fn set_state(&mut self, state_num: usize) {
        self.state = (0..state_num).map(|x| VecDeque::new()).collect();
    }
    fn add_to_pile(&mut self, ind: usize, chars: &str) {
        self.state[ind].push_front(chars.chars().nth(0).unwrap());
    }
    fn add_move(&mut self, mo: (i32, i32, i32)) {
        self.moves.push(mo);
    }

    fn read_top(&self) -> String {
        let mut out = String::new();
        for queue in self.state.iter() {
            if let Some(val) = queue.back() {
                out.push(*val);
            }else{
                out.push(' ');
            }
        }
        out
    }

    fn move_all(&mut self) {
        for (many, from, to) in self.moves.clone().into_iter() {
            for _i in 0..many {
                self.move_pile(from as usize, to as usize);
            }
        }
    }
    fn move_all2(&mut self) {
        for (many, from, to) in self.moves.clone().into_iter() {
            let from = from as usize;
            let to = to as usize;

            //let from = &mut self.state[from]; 
            //let to = &mut self.state[to]; 
            //(0..many).map(|_|from.pop_back()).rev().for_each(|x| if let Some(val) = x {to.push_back(val)});
            let mut stack = vec![];
            for i in (0..many){
                stack.push(self.state[from].pop_back());
            }
            for x in stack.into_iter().rev(){
                if let Some(val) = x {
                    self.state[to].push_back(val);
                }
            }
        }
    }
    fn move_pile(&mut self, from: usize, to: usize) {
        if let Some(val) = self.state[from].pop_back() {
            self.state[to].push_back(val);
        }
    }
}

fn inputReading() -> Input {
    let mut lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let stack_re = Regex::new(r"(   |\[([A-Z])\]) ?").expect("");
    let move_re = Regex::new(r"move (\d+) from (\d+) to (\d+)").expect("");

    let mut input = Input::new();
    for (ind, line) in lines.lines().enumerate() {
        if ind == 0 {
            input.set_state(stack_re.captures_iter(line).count());
        }
        if stack_re.is_match(line) {
            for (ind, cap) in stack_re.captures_iter(line).enumerate() {
                if let Some(txt) = cap.get(2) {
                    input.add_to_pile(ind, txt.as_str());
                }
            }
        } else if move_re.is_match(line) {
            for cap in move_re.captures_iter(line) {
                input.add_move((
                        cap[1].parse().unwrap(),
                        cap[2].parse::<i32>().unwrap() -1 ,
                        cap[3].parse::<i32>().unwrap() -1,
                        ));
            }
        }
    }
    input
}

fn fstar(mut input: Input) -> Output {
    input.move_all();
    input.read_top()
}
fn sstar(mut input: Input) -> Output {
    input.move_all2();
    input.read_top()
}

fn main() {
    let input = inputReading();
    println!("first star   : {}", fstar(input.clone()));
    println!("second start : {} \n", sstar(input.clone()));
}
