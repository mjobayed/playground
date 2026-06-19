import fastify, { FastifyReply } from "fastify";

const app = fastify({ logger: true });

app.get("/", async (_, reply: FastifyReply) => {
  reply.code(200).send({ message: "OK" });
});

app.post("/", async (_, reply) => {
  reply.code(201).send({ message: "created" });
});

export default app;
