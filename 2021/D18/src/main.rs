use std::fs;

mod pair;
mod value;

use crate::pair::Pair;

const FILE_PATH:&str = "input";

fn first_star(pairs:Vec<Pair>){

    let mut res= None;

    for mut pair in pairs {
        pair.reduce();
        match res {
            None => {
                res = Some(pair);
            },
            Some(last) => {
                let mut new_pair=Pair::from_pairs(last,pair); 
                new_pair.reduce();
                res = Some(new_pair);
            }
        }
    }

    match res{
        None => {
            panic!("No result");
        },
        Some(pair) => {
            println!("first star:{}",pair.magnitude());
        }
    }
}

fn second_star(pairs:Vec<Pair>){
    let mut res:i64= 0;
    for i in 0..pairs.len() {
        for j in i+1..pairs.len() {
            for (a,b) in [(i,j),(j,i)]{
            let mut new_pair=Pair::from_pairs(pairs[a].clone(),pairs[b].clone()); 
            new_pair.reduce();
            res = std::cmp::max(res,new_pair.magnitude());
            }
        }
    }
    println!("second star:{}",res);
}


fn main() {
    let contents = fs::read_to_string(FILE_PATH)
        .expect("Should have been able to read the file"); 
    let pairs:Vec<Pair>=contents.lines().map(|x|{
        Pair::from_str(x).unwrap().0
    }).collect();
    first_star(pairs.clone());
    second_star(pairs.clone());
}




#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn explode_split() {
        let value = [
        ("[[[[1,1],[2,2]],[3,3]],[4,4]]","[[[[1,1],[2,2]],[3,3]],[4,4]]"),
        ("[[[[[1,1],[2,2]],[3,3]],[4,4]],[5,5]]","[[[[3,0],[5,3]],[4,4]],[5,5]]"),
        ("[[[[[4,3],4],4],[7,[[8,4],9]]],[1,1]]","[[[[0,7],4],[[7,8],[6,0]]],[8,1]]"),
        ];
        for (input,expected) in value {
            let mut pair = Pair::from_str(input).unwrap().0;
            pair.reduce();
            assert_eq!(pair.to_string(),expected);
        }

    }
}
