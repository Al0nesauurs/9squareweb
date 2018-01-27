let firebase = require('firebase')

let mqtt = require('mqtt'); //includes mqtt server 
let mongodb = require('mongodb'); // includes mongoDB 
let mongodbClient = mongodb.MongoClient; //initialises the mongoDB client
let mongodbURI = 'mongodb://127.0.0.1:27017/db'; //activating the MongoDB port 27017, here TempMontor is the name of the database
let deviceRoot = "room1/temp"; //deviceroot is topic name given in arduino code 
let collection,client; //initialise collection and client
let order = []
let start = false
let i = 0, step = 0, set = 0
let config = {
  apiKey: "AIzaSyBN4-YyLBgRJe-_ZuBe1OtpOYYXsw29P6c",
  authDomain: "nafire-18969.firebaseapp.com",
  databaseURL: "https://nafire-18969.firebaseio.com",
  projectId: "nafire-18969",
  storageBucket: "nafire-18969.appspot.com",
  messagingSenderId: "463051690711"
}
let a = firebase.initializeApp(config)

getRoomnumber()
mongodbClient.connect(mongodbURI, (err, database) => {
  if(err) throw err;
  db=database.db("mydb")
  collection=db.collection("real"); //name of the collection in the database
  client=mqtt.connect({ host: 'localhost', port: 1883 }); //connecting the mqtt server with the MongoDB database
  client.subscribe(deviceRoot); //subscribing to the topic name 
  client.on('message', insertEvent);
})

function getRoomnumber() {
  const readline = require('readline');
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
  });
  
  rl.question('Enter Room number ', (answer) => {
    rl.close();
    roomnum = answer
    getDataFirebase(answer)
    
  })
}
function insertEvent(topic,payload) {  
  let key=topic.replace(deviceRoot,'');
  console.log(payload.toString())
  if (start === "START") {
    if (payload.toString() === order[i]) {
      i++
      step++
      console.log(step + 'CORRECT')
      if (i === order.length-1)
      {
          set++
          i = 0
      }
    } else {
        console.log('MISSING')
    }
  }
}

function getDataFirebase (roomnum) {
  firebase.database().ref('/rooms/room' + roomnum +'/order/').on("value", (snapshot) => {
    snapshot.forEach((childSnapshot) => {
        order.push(childSnapshot.val().substring(0,1))
    })        
    console.log("READING DATA")
    console.log(order)
  },  (errorObject) => {
    console.log("The read failed: " + errorObject.code)
  })
  firebase.database().ref('/rooms/room' + roomnum +'/start/').on("value", (snapshot) => {
    start = snapshot.val()
    if (start === 'START') {
      console.log('START')
    } else if (start === 'END') {   
        collection.insert({  //FOR MONGODB
          event: { step: step, set: set, when:new Date() } 
        }).then(() => {
            firebase.database().ref('/mqtt').set({  // FOR FIREBASE
                event: { step: step, set: set, when:new Date() } 
            }).then(() => {
              firebase.database().ref('/rooms/room' + roomnum).update({
                  start: "READY"
                })
              i = 0; step = 0; set = 0;  
              console.log('Insert Complete')
            })
        })
      console.log('END')
    } else if (!start){
        console.log('ROOM NOT AVA')
    }    
  })
}