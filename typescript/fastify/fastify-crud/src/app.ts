import fastify, { FastifyReply, FastifyRequest } from "fastify";
import { rootPostBody } from "./types/appTypes.js";

const app = fastify({ logger: true });

app.get("/", async (_, reply: FastifyReply) => {
  reply.code(200).send({ message: "OK" });
});

app.post<{ Body: rootPostBody }>("/", async (request, reply: FastifyReply) => {
  const { name, age } = request.body;
  reply.code(201).send({ message: "The response", name, age });
});

export default app;
