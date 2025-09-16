<?php 

   



    

declare(strict_types= 1);
require_once("../includes/dbh.inc.php"); // Ensure this file connects to your MySQL database correctly
require_once("../includes/session.inc.php");

if ($_SERVER["REQUEST_METHOD"] === "POST") {
    $name = $_POST["name"];
    $email = $_POST["email"];
    $pwd = $_POST["pwd"];
    $username = $_POST["username"];
    $blood = $_POST["blood"];

    try {
        // Errors array
        $errors = [];
    
        // Validate input
        if (checkInput($name, $email, $pwd, $username, $blood)) {
            $errors["check_input"] = "Fill all fields!";
        }
        if (username_exists($pdo, $username)) {
            $errors["user_exists"] = "User already exists!";
        }
        if (email_exists($pdo, $email)) {
            $errors["email_exists"] = "Email already exists!";
        }

        if ($errors) {
            $_SESSION["patient_error_register"] = $errors;
            header("Location:register.php");
            die();
        }

        insert_user($pdo, $name, $username, $pwd, $email, $blood);

        $_SESSION["patient"] = $username;

        header("Location:register.php?register=success");

        // Closing connections
        $pdo = null;
        die();

    } catch (PDOException $e) {
        die("Query failed: " . $e->getMessage());
    }

} else {
    header("Location:register.php");
    die();
}

function checkInput(string $name, string $email, string $pwd, string $username, string $blood) {
    return empty($name) || empty($email) || empty($pwd) || empty($username) || empty($blood);
}

function username_exists(object $pdo, string $username) {
    $query = "SELECT username FROM patient WHERE username = :username;";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(":username", $username);
    $stmt->execute();
    $result = $stmt->fetch(PDO::FETCH_ASSOC);
    
    return $result ? true : false;
}

function email_exists(object $pdo, string $email) {
    $query = "SELECT email FROM patient WHERE email = :email;";
    $stmt = $pdo->prepare($query);
    $stmt->bindParam(":email", $email);
    $stmt->execute();
    $result = $stmt->fetch(PDO::FETCH_ASSOC);

    return $result ? true : false;
}

function insert_user(object $pdo, string $name, string $username, string $pwd, string $email, string $blood) {
    $query = "INSERT INTO patient (name, username, pwd, email, blood) VALUES (:name, :username, :pwd, :email, :blood);";
    $stmt = $pdo->prepare($query);
    $options = [
        "cost" => 10
    ];
    $hashedPwd = password_hash($pwd, PASSWORD_BCRYPT, $options);
    $stmt->bindParam(":username", $username);
    $stmt->bindParam(":pwd", $hashedPwd);
    $stmt->bindParam(":email", $email);
    $stmt->bindParam(":blood", $blood);
    $stmt->bindParam(":name", $name);
    
    if (!$stmt->execute()) {
        // Handle error if execute fails
        throw new PDOException("Insert user failed: " . implode(", ", $stmt->errorInfo()));
    }
}



    
?>