<?php

 
session_start(); // Start the session

// Optionally, you can set session timeout here
$inactive = 600; // 10 minutes of inactivity

// Check if the session timeout variable is set
if (isset($_SESSION['timeout'])) {
    $session_life = time() - $_SESSION['timeout'];
    // If the session has been inactive for too long, destroy the session
    if ($session_life > $inactive) {
        session_unset(); // Clear the session variables
        session_destroy(); // Destroy the session
        header("Location: login.php"); // Redirect to login page
        exit(); // Make sure to exit after redirect
    }
}

// Update the timeout variable to the current time
$_SESSION['timeout'] = time();



?>