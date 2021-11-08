import express from 'express';
import cors from 'cors';
import cookieParser from 'cookie-parser';
const app = express();
app.use(cors());
app.use(cookieParser());
app.use(express.json());
app.use(express.urlencoded({
    extended: true
}));

let init_endpoints = (app) => {
    app.get('/get/:name)', (req,res) => {
        res.send({});
    });
    app.post('/post/:name', (req,res) => {
        res.send({});
    });
    app.put('/put/:name', (req,res) => {
        res.send({});
    });
    app.patch('/patch', (req,res) => {
        res.send({});
    });
    app.delete('/delete', (req,res) => {
        res.send({});
    });
};

let init_app = (app, port = 8000) => {
    app.listen(port);
};

console.log("server module");

