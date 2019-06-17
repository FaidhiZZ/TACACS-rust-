se std::io::{BufRead,BufReader};
use std::net::TcpListener;
use std::thread;
use std::collections::HashMap;


fn main()
{
  let listener = TcpListener::bind("0.0.0.0:3333").unwrap(); //Binds socket

  println!("Listening started...");

  for stream in listerner.incoming() //Listens for connections
  {
    thread::spawn(||
    {
      //Hashmap acts as database
      let auth:HashMap<String, &str> =
      [("faidhi".to_string(),"666"),
      ("hero".to_string(),"123")].iter().cloned().collect();

      let mut username = String::new();
      let mut password = String::new();

      let stream = stream.unwrap();

      println!("Connection made with: {}", stream.peer_addr().unwrap());

      let mut reader = BufReader::new(&stream);

      //Receives data from client
      reader.read_line(&mut username).expect("ERROR");
      reader.read_line(&mut password).expect("ERROR");

      username.pop(); //Removes new line
      let user = username; //Changes string to &str

      if auth.contains_key(&user) == true{
          let str = auth.get(&user); //Get password
          let s = str.unwrap();
          let pass = s.to_string();

          if password == pass{
              println!("Authentication successful");
          }
          else{
              println!("Wrong password");
          }
      }
      else{
          println("Username not found");
      }

      std::process::exit(0);

    });
  }
}

