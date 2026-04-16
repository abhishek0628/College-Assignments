# from flask import Flask, request, jsonify
# from flask_cors import CORS

# from parser import parse_input
# from omas_to_rbn import encode_to_rbn
# from crp_solver import check_safety

# app = Flask(__name__)
# CORS(app)

# @app.route("/check", methods=["POST"])
# def check():
#     data = request.json["text"]

#     omas = parse_input(data)
#     rbn = encode_to_rbn(omas)
#     result = check_safety(rbn)

#     return jsonify({
#         "result": result
#     })

# if __name__ == "__main__":
#     app.run(debug=True)

from flask import Flask, request, jsonify
from flask_cors import CORS

from parser import parse_input
from omas_to_rbn import encode_to_rbn
from crp_solver import check_safety

app = Flask(__name__)
CORS(app)

@app.route("/check", methods=["POST"])
def check():
    try:
        data = request.json.get("text", "")

        omas = parse_input(data)
        rbn = encode_to_rbn(omas)
        result = check_safety(rbn)

        return jsonify(result)   # 🔥 IMPORTANT FIX

    except Exception as e:
        return jsonify({
            "safe": False,
            "reason": str(e)
        }), 500


if __name__ == "__main__":
    app.run(debug=True)