// // // async function checkSafety() {
// // //     const text = document.getElementById("input").value;

// // //     const res = await fetch("http://127.0.0.1:5000/check", {
// // //         method: "POST",
// // //         headers: {
// // //             "Content-Type": "application/json"
// // //         },
// // //         body: JSON.stringify({ text })
// // //     });

// // //     const data = await res.json();

// // //     const result = data.result;

// // //     let output = "";

// // //     output += result.summary + "\n\n";

// // //     if (result.logs) {
// // //         output += result.logs.join("\n");
// // //     }

// // //     document.getElementById("output").innerText = output;
// // // }

// // // Read file and put into textarea
// // document.getElementById("fileInput").addEventListener("change", function (event) {
// //     const file = event.target.files[0];

// //     if (!file) return;

// //     const reader = new FileReader();

// //     reader.onload = function (e) {
// //         document.getElementById("input").value = e.target.result;
// //     };

// //     reader.readAsText(file);
// // });


// // async function checkSafety() {
// //     const text = document.getElementById("input").value;

// //     if (!text.trim()) {
// //         document.getElementById("output").innerText = "Please provide input.";
// //         return;
// //     }

// //     document.getElementById("output").innerText = "Processing...";

// //     try {
// //         const res = await fetch("http://127.0.0.1:5000/check", {
// //             method: "POST",
// //             headers: {
// //                 "Content-Type": "application/json"
// //             },
// //             body: JSON.stringify({ text })
// //         });

// //         const data = await res.json();

// //         const result = data.result;

// //         let output = "";

// //         output += result.summary + "\n\n";

// //         if (result.logs) {
// //             output += result.logs.join("\n");
// //         }

// //         document.getElementById("output").innerText = output;

// //     } catch (err) {
// //         document.getElementById("output").innerText =
// //             "Error connecting to backend:\n" + err;
// //     }
// // }

// async function checkSafety() {
//     const text = document.getElementById("input").value;

//     try {
//         const res = await fetch("http://127.0.0.1:5000/check", {
//             method: "POST",
//             headers: {
//                 "Content-Type": "application/json"
//             },
//             body: JSON.stringify({ text })
//         });

//         const data = await res.json();

//         console.log("Backend response:", data);

//         document.getElementById("result").innerText =
//             data.safe
//                 ? "SAFE SYSTEM ✅"
//                 : "UNSAFE SYSTEM ❌\nReason: " + data.reason;

//     } catch (err) {
//         document.getElementById("result").innerText =
//             "Frontend error: " + err.message;
//     }
// }

document.getElementById("fileInput").addEventListener("change", function (event) {
    const file = event.target.files[0];

    if (!file) return;

    const reader = new FileReader();

    reader.onload = function (e) {
        document.getElementById("input").value = e.target.result;
    };

    reader.readAsText(file);
});

async function checkSafety() {
    const text = document.getElementById("input").value;

    if (!text.trim()) {
        document.getElementById("output").innerText = "INVALID INPUT\nEmpty text provided.";
        return;
    }

    try {
        const res = await fetch("http://127.0.0.1:5000/check", {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify({ text })
        });

        const data = await res.json();

        console.log("Response:", data);

        if (data.safe === undefined) {
            document.getElementById("output").innerText =
                "INVALID RESPONSE FROM BACKEND\n" + JSON.stringify(data, null, 2);
            return;
        }

        document.getElementById("output").innerText =
            data.safe
                ? "✅ SAFE SYSTEM\n\n" + data.reason
                : "🚨 UNSAFE SYSTEM\n\n" + data.reason;

    } catch (err) {
        document.getElementById("output").innerText =
            "FRONTEND ERROR:\n" + err.message;
    }
}