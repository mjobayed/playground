import fastify from "fastify";

const app = fastify({
  logger: true,
  ajv: {
    customOptions: {
      coerceTypes: false,
    },
  },
});

app.get("/", async (_, reply) => {
  reply.code(200).send({ message: "OK" });
});

export default app;
