use std::fs;
use itertools::Itertools;


const INPUT_FILE:&str = "input";
const OVERLAPPING_BEACONS:i32 = 12;




fn all_rotation() -> Vec<(())> {
    let permutation = vec![0,1,2].iter().permutation(3).map(|x| {x.collect_turple().unwrap()});
    let rotation = [1,-1].iter().cartesian_product([1,-1]).cartesian_product([1,-1]).map(|((x,y),z)| {(x,y,z}}).collect::<Vec<_>>())
    permutation.cartesian_product(rotation)

}



#[derive(Debug)]
struct Coordinate{
    x:i32,
    y:i32,
    z:i32,
}

impl Coordinate {
    fn from(coordinate:(i32,i32,i32)) -> Self {
        Coordinate { x: coordinate.0, y: coordinate.1, z:coordinate.2 }
    }
}

#[derive(Debug)]
struct Scanner{
    beacons:Vec<Coordinate>,
    position: Option<Coordinate>
}

impl Scanner{
    fn new() ->Self{
        Scanner{ beacons:vec![], position:None }
    }
    fn from_input(stringa:&str)->Vec<Self>{
        let mut scanners = vec![];
        for line in stringa.lines(){
            if line.starts_with("---"){
                scanners.push(Scanner::new());
            }else{
                let splitted:Vec<&str>=line.split(",").collect();
                if splitted.len() == 3 {
                    let coordinate=Coordinate::from((
                        splitted[0].parse::<i32>().unwrap(),
                        splitted[1].parse::<i32>().unwrap(),
                        splitted[2].parse::<i32>().unwrap()
                    ));
                    scanners.last_mut().unwrap().beacons.push(coordinate);
                }
            }
        }
        scanners
    }
    
}



fn main() {
    let contents = fs::read_to_string(INPUT_FILE)
        .expect("Should have been able to read the file"); 
    let scanners=Scanner::from_input(contents.as_str());
    print("{}",all_rotation());     
   
}

