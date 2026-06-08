import app from "./app.js";

const PORT = 3000;

const start = async () => {
  try {
    console.log(`Server started at http://localhost:${PORT}\n`);
    app.listen({ port: PORT });
  } catch (err) {
    app.log.error(err);
    process.exit(1);
  }
};

start();
