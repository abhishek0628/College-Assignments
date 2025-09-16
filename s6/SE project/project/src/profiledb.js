//profiledb.js
const mongoose = require("mongoose");
async function main() {
  await mongoose.connect(
    "mongodb://127.0.0.1:27017/myblog",
    { useNewUrlParser: true }
    
  );
  console.log("profile connected");
}
main();
const profileSchema = new mongoose.Schema({
  username: String,
  fullname: String,
  email: String,
  password:String,
  type:String,
  dp: String,
  bio: String,
  weblink:String,
  facebook:String,
  whatsapp:String,
  twitter:String,
  instagram:String,
  phoneno:String
});

const Profile = mongoose.model("profile", profileSchema);
module.exports = Profile;
