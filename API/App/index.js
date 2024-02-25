
document.getElementById("fetchButton").addEventListener('click', () => {

    let valueUsername = document.querySelector('#username_form').value;
    let valuePassword = document.querySelector('#password_form').value;

    if ( valueUsername.length <= 5 )
    {
        alert(`Invalid Forms`);
        window.location.reload();
    }
    else if ( valuePassword.length <= 5 )
    {
        alert(`Invalid Forms`);
        window.location.reload();
    }
    else
    {
        alert(`OK`);
    }
})