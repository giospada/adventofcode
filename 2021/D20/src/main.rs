use std::fs;

const FILE_INPUT: &str = "input";
const ITERATION:usize = 50;


#[derive(Clone)]
struct MaskedLine {
    map: Vec<bool>,
}

impl MaskedLine {
    fn from_str(stringa: &str) -> Self {
        let mut res = Self { map: vec![] };
        stringa.chars().for_each(|x| {
            match match x {
                '#' => Some(true),
                '.' => Some(false),
                _ => None,
            } {
                Some(value) => res.push(value),
                None => (),
            };
        });
        res
    }

    fn get(&self, i: i32) -> Option<bool> {
        if i < 0 {
            return None;
        }
        let i = i as usize;
        if self.map.len() <= i {
            return None;
        }
        Some(self.map[i])
    }

    fn push(&mut self, val: bool) {
        self.map.push(val);
    }

    fn set(&mut self, i: usize, value: bool) {
        self.map[i] = value;
    }

    fn count(&self) -> i32 {
        self.map
            .iter()
            .fold(0, |acc, x| acc + (if *x { 1 } else { 0 }))
    }
}

#[derive(Clone)]
struct MaskedImage {
    outcell:bool,
    map: Vec<MaskedLine>,
}

impl MaskedImage {
    fn add_padding(&mut self,padding:usize){
        let len_row = self.map[0].map.len()+padding*2;
        let array = (0..len_row).map(|_|false).collect::<Vec<bool>>();
        self.map.iter_mut().for_each(|x| {
            (0..padding).for_each(|_| {
                x.map.push(false);
                x.map.insert(0,false);
            });
        } );
        (0..padding).for_each(|_| {
            self.map.insert(0,MaskedLine{map:array.clone() });
        });
        (0..padding).for_each(|_| {
            self.map.push(MaskedLine{map:array.clone() });
        });
    }
    fn compute_new_img(&self, mask: &MaskedLine) -> Self {
        let mut clone = (*self).clone();
        //vale solo per l'input corrente
        clone.outcell = !clone.outcell;
        self.map.iter().enumerate().for_each(|(i, line)| {
            line.map.iter().enumerate().for_each(|(j, _)| {
                clone.set(i, j, self.caluclate_value(i, j, mask));
            });
        });
        clone
    }

    fn get(&self, i: i32, j: i32) -> Option<bool> {
        if i < 0 {
            return None;
        }
        let i = i as usize;
        if self.map.len() <= i {
            return None;
        }
        self.map[i].get(j)
    }

    fn caluclate_value(&self, i: usize, j: usize, mask: &MaskedLine) -> bool {
        // i<-j
        let mut pos = 0;
        (-1..2).into_iter().for_each(|deltaX| {
            (-1..2).into_iter().for_each(|deltaY| {
                let value = match self.get(deltaX + (i as i32), deltaY + (j as i32)) {
                    Some(x) => x,
                    None => self.outcell,
                };
                pos = (if value { 1 } else { 0 }) + pos * 2;
            });
        });
        mask.get(pos).unwrap()
    }

    fn set(&mut self, i: usize, j: usize, value: bool) {
        self.map[i].set(j, value);
    }

    fn from_str(stringa: Vec<&str>) -> Self {
        let mut res = Self { map: vec![], outcell:false };
        stringa.iter().for_each(|x| {
            res.push(MaskedLine::from_str(x));
        });
        res
    }

    fn push(&mut self, val: MaskedLine) {
        self.map.push(val);
    }
    fn count(&self) -> i32 {
        self.map.iter().fold(0, |acc, x| acc + x.count())
    }
}





fn main() {
    let mut lines = fs::read_to_string(FILE_INPUT).expect("impossibile aprire  il file ");

    let lines: Vec<&str> = lines.lines().into_iter().collect();
    let maskedLine = MaskedLine::from_str(lines[0]);
    let mut maskedImage =
        MaskedImage::from_str(lines.into_iter().skip(2).into_iter().collect::<Vec<&str>>());

    

    maskedImage.add_padding(ITERATION);
    (0..ITERATION).for_each(|_|{
        maskedImage = maskedImage.compute_new_img(&maskedLine);
    });

    //maskedImage = maskedImage.compute_new_img(&maskedLine);
    //println!("{}", maskedImage.to_string());
    //maskedImage = maskedImage.compute_new_img(&maskedLine);
    println!("{}", maskedImage.count());
}

impl ToString for MaskedLine {
    fn to_string(&self) -> String {
        self.map
            .iter()
            .map(|x| if *x { '#' } else { '.' })
            .collect::<String>()
    }
}

impl ToString for MaskedImage {
    fn to_string(&self) -> String {
        self.map
            .iter()
            .map(|x| format!("{}\n", x.to_string()))
            .collect::<String>()
    }
}
