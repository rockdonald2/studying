// Complete the minimumNumber function below.
function minimumNumber(n, password) {
    // Return the minimum number of characters to make the password strong
    const lengthOfPwd = 6;

    let missingTypes = function(password) {
        let missing = 0;
        if (!(password.match(/[a-z]/))) {
            missing++;
        }
        if (!(password.match(/[A-Z]/))) {
            missing++;
        }
        if (!(password.match(/[0-9]/))) {
            missing++;
        }
        if (!(password.match(/\W/))) {
            missing++;
        }

        return missing;
    }

    if (n >= 6 && password.match(/[a-z]/) && password.match(/[A-Z]/) && password.match(/[0-9]/) && password.match(/\W/)) {
        return 0;
    } else if (password.match(/[a-z]/) && password.match(/[A-Z]/) && password.match(/[0-9]/) && password.match(/\W/)) {
        return lengthOfPwd - n;
    } else if (n >= 6 && !(password.match(/[a-z]/) && password.match(/[A-Z]/) && password.match(/[0-9]/) && password.match(/\W/))) {
        return missingTypes(password);
    } else if (n < 6 && n > 3 && ((password.match(/[a-z]/g) ? password.match(/[a-z]/g).length == n : false) || (password.match(/[A-Z]/g) ? password.match(/[A-Z]/g).length == n : false) || (password.match(/[0-9]/g) ? password.match(/[0-9]/g).length == n : false) || (password.match(/\W/g) ? password.match(/\W/g).length == n : false))) {
        return lengthOfPwd - (missingTypes(password));
    } else {
        if (n + missingTypes(password) < lengthOfPwd) {
            return lengthOfPwd - n;
        } else {
            return missingTypes(password);
        }
    }
}