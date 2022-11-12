from flask import Flask, redner_template, request

app = Flask(__name__)

@app.route("/", methods=["GET"])
def index:
    return render_template("index.html")

@app.route("/greet", methods=["GET"])
def greet():
    return render_template("greet.html", first_name=request.form.get("first_name", "world"))