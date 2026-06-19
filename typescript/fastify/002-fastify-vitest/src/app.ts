import fastify, { FastifyReply } from "fastify";

const app = fastify({
  logger: true,
  ajv: {
    customOptions: {
      coerceTypes: false,
    },
  },
});

app.get("/", async (_, reply: FastifyReply) => {
  reply.code(200).send({ message: "OK" });
});

app.post<{ Body: { title: string } }>("/", async (request, reply) => {
  const { title } = request.body;
  reply.code(201).send({ title });
});

export default app;
