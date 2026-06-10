import fastify, { FastifyReply, FastifyRequest } from "fastify";

const app = fastify({ logger: true });

app.get("/", async (_, reply: FastifyReply) => {
  reply.code(200).send({ message: "OK" });
});

app.post("/", async (_request: FastifyRequest, reply: FastifyReply) => {
  reply.code(201).send({ message: "POST request received" });
});

export default app;
