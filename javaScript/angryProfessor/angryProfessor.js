// Complete the angryProfessor function below.
function angryProfessor(k, a) {
    return a.filter((std) => std <= 0).length >= k ? "NO" : "YES";
}

console.log(angryProfessor(3, [-1, -3, 4, 2, -3]));