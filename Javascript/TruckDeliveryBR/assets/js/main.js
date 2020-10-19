const zip = document.querySelector('#zip');
const address = document.querySelector('#address');
const city = document.querySelector('#city');
const state = document.querySelector('#state')

const zipSearch = (e) => {
    const typedZip = e.target.value;

    if (typedZip.length != 8) {
        return;
    }

    fetch(`https://viacep.com.br/ws/${typedZip}/json`)
    .then((res) => { return res.json() })
    .then((data) => {
        address.value = data.logradouro;
        city.value = data.localidade;
        state.value = data.uf;
        zip.value = data.cep;
    })
}

zip.addEventListener('input', zipSearch);