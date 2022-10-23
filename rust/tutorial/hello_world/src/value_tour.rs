use std::{collections::HashMap, thread};

pub fn value_tour() {               // scope 1
    // let authenticated = true;
    // if authenticated {              // scope 2
    //     todo!();
    // } else {                        // scope 3
    //     todo!()
    // }

    // modify value
    // let mut total = 0;
    // total += 1;

    // pass to function
    let name = "simon".to_string();
    print_my_name(name);

    // pass by ref
    let mut map: HashMap<String, String> = HashMap::new();
    print_map(&map);
    insert_map(&mut map);

    // multithreaded
    let mut data = vec![1, 2, 3];
    thread::spawn(move || {
        data.push(5);
    });
    // data.push(4);
}

fn print_my_name(name: String) {
    println!("{}", name);
}

fn print_map(map: &HashMap<String, String>) {
    todo!();
}

fn insert_map(map: &mut HashMap<String, String>) {
    todo!();
}