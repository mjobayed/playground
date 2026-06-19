import fastify, { FastifyReply } from "fastify";

const app = fastify({ logger: true });

app.get("/", async (_, reply: FastifyReply) => {
  reply.code(200).send({ message: "OK" });
});

export default app;
