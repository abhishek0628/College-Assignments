<?php 

    declare(strict_types=1);

    // Enable error reporting for debugging
    error_reporting(E_ALL);
    ini_set('display_errors', 1);
    
    // Database credentials
    $host = "127.0.0.1"; // Use 127.0.0.1 instead of localhost
    $dbname = "BBMS";
    $dbusername = "root";
    $dbpassword = 'abhi@321';
    
    try {
        // Connect to the database
        $pdo = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $dbusername, $dbpassword);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        echo "Database connection successful.<br>";
    } catch (PDOException $e) {
        die('Connection failed: ' . $e->getMessage());
    }
    
    // Function to insert a new user
    function insert_user(object $pdo, string $name, string $username, string $pwd, string $email): bool
    {
        try {
            // Check if username or email already exists
            if (user_exists($pdo, $username, $email)) {
                throw new Exception("Username or email already exists.");
            }
    
            // Prepare the SQL statement
            $query = "INSERT INTO admin (name, username, pwd, email) VALUES (:name, :username, :pwd, :email);";
            $stmt = $pdo->prepare($query);
    
            // Hash the password
            $options = ["cost" => 10];
            $hashedPwd = password_hash($pwd, PASSWORD_BCRYPT, $options);
    
            // Bind parameters
            $stmt->bindParam(":name", $name);
            $stmt->bindParam(":username", $username);
            $stmt->bindParam(":pwd", $hashedPwd);
            $stmt->bindParam(":email", $email);
    
            // Execute the statement
            if ($stmt->execute()) {
                echo "User inserted successfully.<br>";
                return true; // Indicate success
            } else {
                echo "Failed to execute the statement.<br>";
                return false; // Indicate failure
            }
        } catch (PDOException $e) {
            // Handle database errors
            die("Database error: " . $e->getMessage());
        } catch (Exception $e) {
            // Handle other errors (like username/email already exists)
            echo $e->getMessage() . "<br>";
            return false; // Indicate failure
        }
    }
    
    // Function to check if username or email already exists
    function user_exists(object $pdo, string $username, string $email): bool
    {
        $query = "SELECT * FROM admin WHERE username = :username OR email = :email;";
        $stmt = $pdo->prepare($query);
        $stmt->bindParam(":username", $username);
        $stmt->bindParam(":email", $email);
        $stmt->execute();
        $result = $stmt->fetch(PDO::FETCH_ASSOC);
        
        return $result !== false; // Return true if user exists
    }
    
    // Example usage
    $name = "John Doe";
    $username = "johndoe"; // Change to a unique username
    $password = "securepassword"; // This is the password to be hashed
    $email = "johndoe@example.com"; // Ensure this email is unique
    
    if (insert_user($pdo, $name, $username, $password, $email)) {
        echo "User insertion was successful.<br>";
    } else {
        echo "User insertion failed.<br>";
    }
    
    // Close the database connection
    $pdo = null;



    
?>