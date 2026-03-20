<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

// Database connection settings
$host = "127.0.0.1"; // Using 127.0.0.1 to avoid potential socket issues
$dbname = "BBMS";
$dbusername = "root"; // Adjust if you have a different username
$dbpassword = "abhi@321"; // Ensure this password is correct

try {
    // Connect to the database
    $pdo = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8mb4", $dbusername, $dbpassword);
    
    // Set the PDO error mode to exception
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $pdo->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC); // Optional: Set default fetch mode

    // Optional: Set character set to UTF-8
    $pdo->exec("SET NAMES 'utf8mb4'");

    // If the connection is successful, print a success message (for debugging purposes)
    // Comment out or remove in production
    echo "Database connection successful.";
} catch (PDOException $e) {
    // Handle connection errors and print an error message
    echo 'Connection failed: ' . $e->getMessage();
}


        
        
        



?>