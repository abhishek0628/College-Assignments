//postdb.js file
const mongoose = require("mongoose");
async function main() {
  await mongoose.connect(
    "mongodb://127.0.0.1:27017/myblog",
    { useNewUrlParser: true }
  );
  console.log("post connected");
}
main()
const postSchema = new mongoose.Schema({
    author: String,
    title: String,
    content: String,
    thumbnail:String,
    date:Number,
    like:Number,
    likedby:[String]
    });
  
    

const PosT = mongoose.model("post", postSchema);
module.exports = PosT