const express=require("express");

const app=express();

app.use("/",express.static("frontend"));

// app.get("/",(req,res)=>{
//     return res.send("Hello from server.");
// })

// app.get("/about",(req,res)=>{
//     return res.send("Hello from about section of server.");
// })

app.listen(8080);